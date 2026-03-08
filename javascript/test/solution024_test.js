var assert = require('assert');
var solution024 = require('../src/euler/solution024');

describe('Solution024', function() {
  describe('answer', function() {
    it('will answer problem 024', function() {
      assert.equal(solution024.answer(), 2783915460);
    });
  });
});