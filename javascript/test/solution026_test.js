var assert = require('assert');
var solution026 = require('../src/euler/solution026');

describe('Solution026', function() {
  describe('answer', function() {
    it('will answer problem 026', function() {
      assert.equal(solution026.answer(), 983);
    });
  });
});
