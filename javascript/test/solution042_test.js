var assert = require('assert');
var solution042 = require('../src/euler/solution042');

describe('Solution042', function() {
  describe('answer', function() {
    it('will answer problem 042', function() {
      assert.equal(solution042.answer(), 162);
    });
  });
});