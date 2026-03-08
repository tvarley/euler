var assert = require('assert');
var solution013 = require('../src/euler/solution013');

describe('Solution013', function() {
  describe('answer', function() {
    it('will answer problem 013', function() {
      assert.equal(solution013.answer(), 5537376230);
    });
  });
});